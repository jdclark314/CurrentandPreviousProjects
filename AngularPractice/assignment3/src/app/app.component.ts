import { Component } from '@angular/core';

@Component({
  selector: 'app-root',
  templateUrl: './app.component.html',
  styles: [`
      .colorText {
          color: white
      }
    `]
  //styleUrls: ['./app.component.css']
})
export class AppComponent {
  title = 'assignment3';
  buttonPress = false;
  buttonClicks = [];
  counter = 0;

  buttonClick() {
    if (this.buttonPress === false) {
      this.buttonPress = true;
    }
    else {
      this.buttonPress = false;
    }
    this.buttonClicks.push(this.counter);
    this.counter++
  }

  getColor() {
    return this.counter > 4 ? 'blue' : 'white';
  }
}
