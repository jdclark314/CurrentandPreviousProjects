import { Component } from '@angular/core';

@Component({
  selector: 'app-root',
  templateUrl: './app.component.html',
  styleUrls: ['./app.component.css']
})
export class AppComponent {
  oddNumbers: number[] = [];
  evenNumbers: number[] = [];

  onGameStarted(currentNumber: number) {
    console.log(currentNumber);
    if (currentNumber % 2 === 0) {
      this.evenNumbers.push(currentNumber);
      console.log(this.evenNumbers);
    }
    else {
      this.oddNumbers.push(currentNumber);
      console.log(currentNumber)
    }
  }
}
