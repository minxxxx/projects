import { Component, OnInit, OnDestroy, NgModule } from '@angular/core';
import { PlatformLocation } from '@angular/common';
import { AuthService } from '../../services/auth.service';

import io from 'socket.io-client';

var notification = new Audio('assets/audio/HospitalWebNotification.ogg');

@Component({
  selector: 'app-home',
  templateUrl: './home.component.html',
  styleUrls: ['./home.component.css']
})
export class HomeComponent implements OnInit, OnDestroy {
  socket: any;
  selectedPatient: number = -1;
  incomingPatients: any = [
    /*{
      code: "A1",
      timeScanned: new Date(),
      eta: "60 min",
      patient: { firstName: 'John', lastName: 'Doe', initial: 'Mr.', idNumber: '0000000000000', dateOfBirth: '1996/08/26', gender: 'Male',
                race: 'white', nextOfKinFirstName: 'Joshua', nextOfKinLastName: 'Doe', nextOfKinCellNumber: '012 345 6789', allergies: 'none', bloodType: 'A+',
                history: 'Took an arrow to the knee', chronicMedication: 'none', medicalAid: 'BestMed', medicalAidNumber: 'AB 00001' },
      requestedMedicalAidClaim: false
    },
    {
      code: "A1",
      timeScanned: new Date(),
      eta: "60min",
      patient: { firstName: 'Jane', lastName: 'Doe', initial: 'Mrs.', idNumber: '0000000000002', dateOfBirth: '1997/02/26', gender: 'Female',
                  race: 'white', nextOfKinFirstName: 'Joshua', nextOfKinLastName: 'Doe', nextOfKinCellNumber: '012 345 6791', allergies: 'none', bloodType: 'O+',
                  history: 'Took an arrow to the knee', chronicMedication: 'none', medicalAid: 'BestMed', medicalAidNumber: 'AB 00001' },
      requestedMedicalAidClaim: true
    }*/
  ];
  

  constructor(
    private authService: AuthService, 
    private location: PlatformLocation
  ) { 
    this.location.onPopState(() => {
      this.authService.logout();
    });

    this.socket = io('http://localhost:2022');
    this.socket.emit('newHospital', sessionStorage.getItem('code'));

    this.socket.on('InboundPatient', this.inboundPatient.bind(this));

    notification.loop = false;
  }

  ngOnInit() {
    notification.load();
  }
  
  ngOnDestroy() {
    this.socket.disconnect();
    this.authService.logout();
  }

  selectedPatientChanged(index) {
    this.selectedPatient = index;
  }

  inboundPatient(msg) {
    notification.play();
    var msg = JSON.parse(msg);
    for (var i = 0; i < this.incomingPatients.length; i++) {
      if (this.incomingPatients[i].patient.idNumber == msg.patient.idNumber) {
        this.incomingPatients[i] = msg;
        return ;
      } else if (this.incomingPatients[i].patient.firstName == msg.patient.firstName
        && this.incomingPatients[i].patient.lastName == msg.patient.lastname) {
        this.incomingPatients[i] = msg;
        return ;
      }
    }
    this.incomingPatients.push(msg);
    
    //var notification = new Audio('../../content/audio/HospitalWebNotification.ogg');
    //notification.play();
  }

  deletePatientFromList() {
    this.incomingPatients.splice(this.selectedPatient, 1);
    this.selectedPatient = -1;
  }

  printSection() {
    window.print();
  }
}

interface Patient {
  firstName: string,
  lastName: string,
  initial: string,
  idNumber: string,
  dateOfBirth: string,
  gender: string,
  race: string,
  bloodType: string,
  nextOfKinFirstName: string,
  nextOfKinLastName: string,
  nextOfKinCellNumber: string,
  medicalAid: string,
  medicalAidNumber: string,
  allergies: string,
  history: string,
  chronicMedication: string
}