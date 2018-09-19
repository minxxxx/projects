var express = require('express'),
  glob = require('glob'),
  bodyParser = require('body-parser');

var logger = require('morgan');

module.exports = function(app, config) {
  var env = process.env.NODE_ENV || 'development';
  app.locals.ENV = env;
  app.locals.ENV_DEVELOPMENT = env == 'development';

  // app.use(favicon(config.root + '/public/img/favicon.ico'));
  app.use(logger('dev'));
  app.use(express.static(config.root + '/public'));
  app.use(bodyParser.json());

  app.use(bodyParser.urlencoded({
    extended: true
  }));

  var controllers = glob.sync(config.root + '/app/controllers/*.js');
  controllers.forEach(function (controller) {
    require(controller)(app);
  });

  app.use(function (req, res, next) {
    var err = new Error('Not Found');
    err.status = 404;
    next(err);
    res.end();
  });

  if(app.get('env') === 'development'){
    app.use(function (err, req, res, next) {
      res.status(err.status || 500);
      res.end();
    });
  }

  app.use(function (err, req, res, next) {
    res.status(err.status || 500);
    res.end();
  });

};
