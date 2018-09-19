/**
 * Instructions to Start
 * 1) From the root, cd into the directory API.
 * 2) Run 'npm install'
 * 3) run 'npm install -g nodemon'
 * 4) Run 'npm run dev'. You should see something like: 'Listening on port: ____'
 */

var express		= require('express');
var http		= require('http');
var bodyParser	= require('body-parser');
var mongoose	= require('mongoose');
var cors		= require('cors');
var socketIO	= require('socket.io');

var apiAuthConfig		= require('./config/security.js');

var mPatientController	= require('./MobileControllers/patientController.js');
var mLoginController	= require('./MobileControllers/loginController.js');
var mUserContoller		= require('./MobileControllers/userController.js');
var mHospitalController	= require('./MobileControllers/hospitalController.js');
var mQrController		= require('./MobileControllers/qrMailController.js');

var hLoginController	= require('./HospitalControllers/hospitalLoginController.js');
var hPatientInbound		= require('./models/HospitalResponeModel.js');

var app				= express();
var server			= http.Server(app);
var io				= socketIO(server);
var port			= process.env.PORT || 2022;
var mobileRouter	= express.Router();
var hospitalRouter	= express.Router();

mongoose.connect('mongodb://localhost:27017/SocialDB', { useMongoClient: true });

var whitelist = [
	'http://localhost:4200'
];
var corsOptions = {
	origin: function(origin, callback) {
		if (whitelist.indexOf(origin) !== -1) {
			return callback(null, true);
		} else {
			callback(new Error('Not Allowed by CORS'));
		}
	}
};
var issuesOptions = {
	origin: true,
	methods: [ 'POST', 'PUT', 'GET', 'DELETE' ],
	credentials: true
};

hospitalRouter.use(cors(corsOptions));
hospitalRouter.all('*', cors(issuesOptions));

var db = mongoose.connection;
db.on('error', console.error.bind(console, 'MongoDB Connection Error!'));

app.use(bodyParser.urlencoded({ extended:false }));
app.use(bodyParser.json());

/* Just to check if the api is returning a response. */
mobileRouter.get('/', (req, res) => {
	res.send('Salutations from the REST Api!')
});
hospitalRouter.get('/', (req, res) => {
	res.send('Salutations from the Hospital REST Api');
});

mobileRouter.route('/login')
	.post(mLoginController.login);
mobileRouter.route('/logout')
	.post(apiAuthConfig.isAuthenticated, mLoginController.logout);
mobileRouter.route('/patient')
	.post(apiAuthConfig.isAuthenticated, mPatientController.getPatientById);
mobileRouter.route('/user/:username')
	.get(apiAuthConfig.isAuthenticated, mUserContoller.getUser);
mobileRouter.route('/user')
	.post(mUserContoller.newUser)
	.put(apiAuthConfig.isAuthenticated, mUserContoller.updateUser)
	.delete(apiAuthConfig.isAuthenticated, mUserContoller.deleteUser);
mobileRouter.route('/hospitals')
	.post(apiAuthConfig.isAuthenticated, mHospitalController.getHospitals);
mobileRouter.route('/resetpassword')
	.post(mUserContoller.resetPassword);
mobileRouter.route('/emailqr')
	.post(mQrController.emailQRCode);

hospitalRouter.route('/login')
	.post(hLoginController.login);
hospitalRouter.route('/logout')
	.post(apiAuthConfig.isAuthenticated, hLoginController.logout);

var connectedHospitals = [
];

mobileRouter.route('/inboundpatient')
	.post(apiAuthConfig.isAuthenticated, (req, res) => {
		console.log('InboundPatient: Inbound Patient');
		var hospitalCode = req.body.hospitalCode || '';
		var hospitalResp = new hPatientInbound();

		hospitalResp.code = req.body.code || '';
		hospitalResp.patient = req.body.patient || null;
		hospitalResp.scannedAt = new Date();

		for (var i = 0; i < connectedHospitals.length; i++) {
			if (connectedHospitals[i].code == hospitalCode) {
				connectedHospitals[i].socket.emit('InboundPatient', JSON.stringify(hospitalResp));
				res.json({ status: true });
				return ;
			}
		}
		res.json({ status: false, msg: 'Hospital not online.' });
	})

io.on('connect', function (socket) {
	console.log('A new hospital has connected.');

	socket.on('newHospital', function (msg) {
		console.log('Hospital Client Id: ' + msg);
		connectedHospitals.push({ socketID: socket.id, code: msg, socket: socket });
	});

	socket.on('InboundPatient', function (msg) {
		console.log('Not here baka.');
	});
	socket.on('disconnect', function (sckt) {
		for (var i = 0; i < connectedHospitals.length; i++) {
			if (connectedHospitals[i].socketID === socket.id) {
				connectedHospitals.splice(i, 1);
				return ;
			}
		}
	});
});

app.use('/mobile', mobileRouter);
app.use('/hospt', hospitalRouter);
server.listen(port, function() {
	console.log('Listening on *:' + port);
});