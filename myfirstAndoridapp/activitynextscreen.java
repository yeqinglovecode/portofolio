package com.example.qingye.workshop;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.widget.TextView;
import android.os.Bundle;

public class NextScreenActivity extends AppCompatActivity {

    private TextView mGreetingText;
    private String myUsernameET;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_next_screen);


        Intent intent=getIntent();
        myUsernameET = intent.getStringExtra("key");
        mGreetingText=(TextView) findViewById(R.id.mGreetingText);
        
        mGreetingText.setText("Hello" + myUsernameET + "!");

    }
}
