#model-view-controller design pattern at AngularJs

#View and Template
In Angular, the **view** is a projection of the **model** through the HTML template. This means that whenever the model changes, 
Angular refreshes the appropriate binding points, which updates the view.

example code:
app/index.html
<html ng-app="phonecatApp">
` <head>
  ...
  <script src="bower_components/angular/angular.js"></script>
  <script src="js/controllers.js"></script>
</head>
<body ng-controller="PhoneListCtrl">

  <ul>
    <li ng-repeat="phone in phones">
      {{phone.name}}
      <p>{{phone.snippet}}</p>
    </li>
  </ul>

</body>
</html>`

We replaced the hard-coded phone list with the ngRepeat directive and two Anuglar expressions:
* The ng-repeat="phone in phones" attribute in the <li> tag is an Angular repeater directive. The repeater tells Angular to create a <li>
element for each phone in the list using the <li> tag as the template.
* The expressions wrapped in curly braces ({{phone.name}} and {{phone.snippet}}) will be replaced by the value of the expressions.

We have added a new directive, called ng-controller, which attaches a PhoneListCtrl controller to the DOM at this point:
* The expressions in curly braces ({{phone.name}} and {{phone.snippet}} denote bindings, which are referring to our application model, 
which is set up in our PhoneListCtrl controller.



##Model and Controller
The data model (a simple array of phones in object literal notation) is now instantiated within the PhoneListCtrl controller. 
The controller is simply a constructor function that takes a $scope parameter:

example code:
app/js/controllers.js:
` var phonecatApp = angular.module('phonecatApp', []);

phonecatApp.controller('PhoneListCtrl', function ($scope) {
  $scope.phones = [
    {'name': 'Nexus S',
     'snippet': 'Fast just got faster with Nexus S.'},
    {'name': 'Motorola XOOM™ with Wi-Fi',
     'snippet': 'The Next, Next Generation tablet.'},
    {'name': 'MOTOROLA XOOM™',
     'snippet': 'The Next, Next Generation tablet.'}
  ];
});`

Here we declared a controller called PhoneListCtrl and registered it in an AngularJS module, phonecatApp. Notice that our ng-app directive (on the <html> tag) now specifies the phonecatApp module name as the module to load when bootstrapping the Angular application.

Although the controller is not yet doing very much, it plays a crucial role. By providing context for our data model, the controller allows us to establish data-binding between the model and the view. We connected the dots between the presentation, data, and logic components as follows:
* The ngController directive, located on the <body> tag, references the name of our controller, PhoneListCtrl (located in the JavaScript file controllers.js).
* The PhoneListCtrl controller attaches the phone data to the $scope that was injected into our controller function. This scope is a prototypical descendant of the root scope that was created when the application was defined. This controller scope is available to all bindings located within the <body ng-controller="PhoneListCtrl"> tag.

##Scope
The concept of a scope in Angular is crucial. A scope can be seen as the glue which allows the template, model and controller to work together. Angular uses scopes, along with the information contained in the template, data model, and controller, to keep models and views separate, but in sync. Any changes made to the model are reflected in the view; any changes that occur in the view are reflected in the model.



#Test
The "Angular way" of separating controller from the view, makes it easy to test code as it is being developed. If our controller is available on the global namespace then we could simply instantiate it with a mock scope object:

example unit test code:
describe('PhoneListCtrl', function(){

  it('should create "phones" model with 3 phones', function() {
    var scope = {},
        ctrl = new PhoneListCtrl(scope);

    expect(scope.phones.length).toBe(3);
  });

});
The test instantiates PhoneListCtrl and verifies that the phones array property on the scope contains three records. This example demonstrates how easy it is to create a unit test for code in Angular. Since testing is such a critical part of software development, we make it easy to create tests in Angular so that developers are encouraged to write them.


##Controller
###mission at this time: add full text search
#####Template:
app/index.html
` 
  <div class="container-fluid">
    <div class="row">
      <div class="col-md-2">
        <!--Sidebar content-->

        Search: <input ng-model="query">

      </div>
      <div class="col-md-10">
        <!--Body content-->

        <ul class="phones">
          <li ng-repeat="phone in phones | filter:query">
            {{phone.name}}
            <p>{{phone.snippet}}</p>
          </li>
        </ul>

      </div>
    </div>
  </div> `
  
We added a standard HTML <input> tag and used Angular's filter function to process the input for the ngRepeat directive.

This lets a user enter search criteria and immediately see the effects of their search on the phone list. This new code demonstrates the following:
* Data-binding: This is one of the core features in Angular. When the page loads, Angular binds the name of the input box to a variable of the same name in the data model and keeps the two in sync.

In this code, the data that a user types into the input box (named query) is immediately available as a filter input in the list repeater (phone in phones | filter:query). When changes to the data model cause the repeater's input to change, the repeater efficiently updates the DOM to reflect the current state of the model.

* Use of the filter filter: The filter function uses the query value to create a new array that contains only those records that match the query.

ngRepeat automatically updates the view in response to the changing number of phones returned by the filter filter. The process is completely transparent to the developer.
