var express = require('express'),
  config = require('./config/config')

// Create our app
var app = express();

require('./config/express')(app, config);

app.listen(config.port, function () {
  console.log('Express server is up on port ' + config.port);
});
