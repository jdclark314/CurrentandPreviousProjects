import { Component } from '@angular/core';

@Component({
  selector: 'app-root',
  templateUrl: './app.component.html',
  styleUrls: ['./app.component.css']
})
export class AppComponent {
  title = 'assignment4';
  counter = 0

  updateCounter(countData: { newCount: number }) {
    this.counter = countData.newCount
  }
}
