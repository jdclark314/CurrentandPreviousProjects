import { EventEmitter, Injectable } from "@angular/core";

import { CounterService } from "./counter.service";

@Injectable()
export class UserService {
    activeUsers = ['Max', 'Anna'];
    inactiveUsers = ['Chris', 'Manu'];

    userUpdated = new EventEmitter<number>();

    constructor(private counterService: CounterService) {}

    setToActive(id: number) {
        this.activeUsers.push(this.inactiveUsers[id]);
        this.inactiveUsers.splice(id, 1);
        this.counterService.updateActiveCount();
    }
    
    setToInactive(id: number) {
        this.inactiveUsers.push(this.activeUsers[id]);
        this.activeUsers.splice(id, 1);
        this.counterService.updateInactiveCount();
      }
}