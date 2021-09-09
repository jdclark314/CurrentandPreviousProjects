import { Component, OnInit } from '@angular/core';

@Component({
  selector: 'app-user-name',
  templateUrl: './user-name.component.html',
  styleUrls: ['./user-name.component.css']
})
export class UserNameComponent implements OnInit {
  userName = "";
  constructor() { }

  ngOnInit(): void {
  }

  isEmpty() {
    if (this.userName.length > 0) {
      return true;
    }
    else {
      return false;
    }
  }

  makeEmpty() {
    this.userName = "";
  }

}
