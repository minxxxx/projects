var path = require('path'),
    rootPath = path.normalize(__dirname + '/..'),
    env = process.env.NODE_ENV || 'development';

var config = {
  development: {
    root: rootPath,
    app: {
      name: 'social_tech'
    },
    port: process.env.PORT || 3000,
    db: 'sqlite://localhost/jellobot-development',
    storage: rootPath + '/data/jellobot-development'
  },

  test: {
    root: rootPath,
    app: {
      name: 'jellobot'
    },
    port: process.env.PORT || 3000,
    db: 'sqlite://localhost/jellobot-test',
    storage: rootPath + '/data/jellobot-test'
  },

  production: {
    root: rootPath,
    app: {
      name: 'jellobot'
    },
    port: process.env.PORT || 3000,
    db: 'sqlite://localhost/jellobot-production',
    storage: rootPath + 'data/jellobot-production'
  }
};

module.exports = config[env];
