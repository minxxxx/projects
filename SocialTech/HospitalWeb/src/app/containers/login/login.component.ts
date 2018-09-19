import { Component, OnInit, ViewChild } from '@angular/core';
import { AuthService } from '../../services/auth.service';
import { User } from '../../interfaces/user';
import { BehaviorSubject  } from 'rxjs/BehaviorSubject';
import { Router } from '@angular/router';

declare var jQuery:any;

@Component({
  selector: 'app-login',
  templateUrl: './login.component.html',
  styleUrls: ['./login.component.css']
})
export class LoginComponent implements OnInit {
  showModal: boolean = false;

  private errMessage;

  constructor(
    private authService: AuthService,
    private router: Router
  ) { }

  ngOnInit() {
  }

  closeModal() {
    this.showModal = false;
  }

  onSubmit(username, password) {
    if (username === '' || password === '') {
      this.errMessage = 'Hospital Code and password required.';
      this.showModal = true;
      return;
    }

    this.authService.login(username, password)
    .subscribe(res => {
      if (res.status) {
        this.router.navigate(['/']);
      } else {
        this.errMessage = res.msg;
       this.showModal = true;
      }
    });
  }
}
