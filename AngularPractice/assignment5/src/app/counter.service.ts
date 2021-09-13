export class CounterService {
    activeToInactiveCounter = 0;
    inactiveToActiveCounter = 0;

    updateActiveCount() {
        this.activeToInactiveCounter++;
        console.log('Acitve to Inactive: ' + this.activeToInactiveCounter);
    }

    updateInactiveCount() {
        this.inactiveToActiveCounter++;
        console.log('Inactive to Active: ' + this.inactiveToActiveCounter);
    }


}