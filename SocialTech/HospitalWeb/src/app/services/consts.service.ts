import { Injectable } from '@angular/core';

@Injectable()
export class ConstsService {
    USE_LOCALHOST: boolean = true;
    
    LOCALHOST_LOGIN_ENDPOINT: string    = "http://localhost:2022/hospt/login";
    API_LOGIN_ENDPOINT: string          = "http://localhost:2022/hospt/login";

    LOCALHOST_LOGOUT_ENDPOINT: string   = "http://localhost:2022/hospt/logout";
    API_LOGOUT_ENDPOINT: string         = "http://localhost:2022/hospt/logout";
}