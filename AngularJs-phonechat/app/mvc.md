#model-view-controller design pattern at AngularJs

#View and Template
In Angular, the **view** is a projection of the **model** through the HTML template. This means that whenever the model changes, 
Angular refreshes the appropriate binding points, which updates the view.

example code:
app/index.html
<html ng-app="phonecatApp">
<head>
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
</html>

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
