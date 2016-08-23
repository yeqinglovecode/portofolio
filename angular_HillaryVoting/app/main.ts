import { platformBrowserDynamic } from '@angular/platform-browser-dynamic';
import { AppModule } from './app.module';

// Compiles the module (asynchronously) with the runtime compiler
// which generates a compiled module factory in memory.
// Then bootstraps with that factory, targeting the browser.
platformBrowserDynamic().bootstrapModule(AppModule);


/*
Copyright 2016 Google Inc. All Rights Reserved.
Use of this source code is governed by an MIT-style license that
can be found in the LICENSE file at http://angular.io/license
*/