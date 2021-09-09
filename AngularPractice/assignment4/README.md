# Assignment4
Assignment Instructions: 
        Create three new components: GameControl, Odd and Even
        The GameControl Component should have buttons to start and stop the game
        When starting the game, an event (holding a incrementing number) should get emitted each second (ref = setInterval())
        The event should be listenable from outside the component
        When stopping the game, no more events should get emitted (clearInterval(ref))
        A new Odd component should get created for every odd number emitted, the same should happen for the Even Component (on even numbers)
        Simply output Odd - NUMBER or Even - NUMBER in the two components
        Style the element (e.g. paragraph) holding your output text differently in both components

This project was generated with [Angular CLI](https://github.com/angular/angular-cli) version 12.2.4.

## Development server

Run `ng serve` for a dev server. Navigate to `http://localhost:4200/`. The app will automatically reload if you change any of the source files.

## Code scaffolding

Run `ng generate component component-name` to generate a new component. You can also use `ng generate directive|pipe|service|class|guard|interface|enum|module`.

## Build

Run `ng build` to build the project. The build artifacts will be stored in the `dist/` directory.

## Running unit tests

Run `ng test` to execute the unit tests via [Karma](https://karma-runner.github.io).

## Running end-to-end tests

Run `ng e2e` to execute the end-to-end tests via a platform of your choice. To use this command, you need to first add a package that implements end-to-end testing capabilities.

## Further help

To get more help on the Angular CLI use `ng help` or go check out the [Angular CLI Overview and Command Reference](https://angular.io/cli) page.
