import * as AuthActions from './auth';
import * as NavigationActions from './navigation';
import * as NotificationActions from './notification';
import * as UserActions from './user';
import * as PatientActions from './patients';
import * as HospitalActions from './hospitals';

export const ActionCreators = Object.assign({}, 
    AuthActions,
    NavigationActions,
    NotificationActions,
    UserActions,
    PatientActions,
    HospitalActions
);