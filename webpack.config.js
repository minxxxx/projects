module.exports = {
	entry: './app/app.jsx',
    output: {
	    path: __dirname,
        filename: './public/bundle.js'
    },
    resolve: {
	    modules: [
	        __dirname,
            'node_modules',
            'app/components',
            'app/components/containers',
            'app/builder',
            'app/pages'
        ],
        alias: {
	        BaseCss: 'app/styles/base',
            //Redux:
            reducers: 'app/reducers/reducers',
            actions: 'app/actions/actions',
            configureStore: 'app/store/ConfigureStore',
            reactHistory: 'app/history/history.jsx'
        },
        extensions: ['.js', '.jsx', '.scss']
    },
    module: {
	    loaders: [
	        {
	            loader: 'babel-loader',
                query: {
	                presets: ['react', 'es2015', 'stage-0']
                },
                test: /\.jsx?$/,
                exclude: /(node_modules|bower_components)/
	        }
        ]
    },
    devtool: 'cheap-module-eval-source-map'
};
