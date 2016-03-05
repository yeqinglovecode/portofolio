package com.example.qingye.workshop;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;

public class NewActivity extends AppCompatActivity {

    private EditText myUsernameET;
    private Button mLoginButton;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_new);

        myUsernameET = (EditText) findViewById(R.id.usernameET);

        mLoginButton = (Button) findViewById(R.id.LoginButton);

        /*mLoginButton.secOnClickListener(new View.OnClickListener()){
            @Override
            public void onClick(View v){
                login();
            }
        }*/

        mLoginButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {


                login(myUsernameET.getText().toString());



            }
        });
    };

    private void login(String name){
        Intent intent = new Intent(this, NextScreenActivity.class);
        intent.putExtra("key", name);
        startActivity(intent);
    }



}

