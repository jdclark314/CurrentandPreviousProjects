import { Component, OnInit, EventEmitter, Output } from '@angular/core';
import { interval } from 'rxjs';

@Component({
  selector: 'app-gamecontrol',
  templateUrl: './gamecontrol.component.html',
  styleUrls: ['./gamecontrol.component.css']
})
export class GamecontrolComponent implements OnInit {
  @Output() gameStarted = new EventEmitter<{ newCount: number } > ();
  counter = 0;

  constructor() { }

  ngOnInit(): void {
  }

  startGame() {
    var intervals = setInterval(function () {
      this.gameStarted.emit({
        newCount: this.counter++
      })
    }, 1000)
    //this.counter = 
    console.log(this.counter)
  }

  endGame() {
    clearInterval()
  }

}
