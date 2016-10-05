## ng-app:
The ng-app attribute represents an Angular directive named ngApp (Angular uses name-with-dashes for its 
custom attributes and camelCase for the corresponding directives which implement them). This directive is used to
flag the html element that Angular should consider to be the root element of our application. This gives application 
developers the freedom to tell Angular if the entire html page or only a portion of it should be treated as the Angular
application.


#####AngularJS script tag:
## script src="bower_components/angular/angular.js":
This code downloads the angular.js script and registers a callback that will be executed by the browser when the 
containing HTML page is fully downloaded. When the callback is executed, Angular looks for the ngApp directive. 
If Angular finds the directive, it will bootstrap the application with the root of the application DOM being the element 
on which the ngApp directive was defined.

#####Double-curly binding with an expression:
##  Nothing here {{'yet' + '!'}}:
This line demonstrates the core feature of Angular's templating capabilities 
– a binding, denoted by double-curlies {{ }} as well as a simple expression 'yet' + '!' used in this binding.

The binding tells Angular that it should evaluate an expression and insert the result into the DOM in place of 
the binding. Rather than a one-time insert, as we'll see in the next steps, a binding will result in efficient 
continuous updates whenever the result of the expression evaluation changes.





#Bootstrapping AngularJs apps
Bootstrapping AngularJS apps automatically using the ngApp directive is very easy and suitable for most cases. 
In advanced cases, such as when using script loaders, you can use imperative / manual way to bootstrap the app.

There are 3 important things that happen during the app bootstrap:
* The injector that will be used for dependency injection is created.
* The injector will then create the root scope that will become the context for the model of our application.
* Angular will then "compile" the DOM starting at the ngApp root element, processing any directives and bindings 
found along the way.

Once an application is bootstrapped, it will then wait for incoming browser events (such as mouse click,
key press or incoming HTTP response) that might change the model. Once such an event occurs, Angular detects if it caused 
any model changes and if changes are found, Angular will reflect them in the view by updating all of the affected bindings.
