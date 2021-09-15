import { Component, ViewChild } from '@angular/core';
import { NgForm } from '@angular/forms';

@Component({
  selector: 'app-root',
  templateUrl: './app.component.html',
  styleUrls: ['./app.component.css']
})
export class AppComponent {
  @ViewChild('f', {static: false}) signupForm: NgForm;
  defaultSubscription = 'advanced';
  user = {
    email: '',
    subscriptionType: '',
    password: ''
  };

  submitted = false;

  onSubmit() {
    this.submitted = true;
    this.user.email = this.signupForm.value.email;
    this.user.subscriptionType = this.signupForm.value.subscription;
    this.user.password = this.signupForm.value.password;
    console.log(this.user.email);
    console.log(this.user.subscriptionType);
    console.log(this.user.password);
  }
}
