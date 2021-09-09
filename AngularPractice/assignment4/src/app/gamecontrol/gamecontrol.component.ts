import { Component, OnInit, EventEmitter, Output } from '@angular/core';
import { interval } from 'rxjs';

@Component({
  selector: 'app-gamecontrol',
  templateUrl: './gamecontrol.component.html',
  styleUrls: ['./gamecontrol.component.css']
})
export class GamecontrolComponent implements OnInit {
  @Output() gameStarted = new EventEmitter<number> ();
  counter = 0;
  interval;

  constructor() { }

  ngOnInit(): void {
  }

  startGame() {
    this.interval = setInterval(() => {
      this.gameStarted.emit(this.counter + 1);
      this.counter++;
      //console.log(this.counter);
    }, 1000)
  }

  endGame() {
    clearInterval(this.interval)
  }

}
