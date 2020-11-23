package com.example.transition;

import androidx.appcompat.app.AppCompatActivity;
import androidx.constraintlayout.widget.ConstraintLayout;
import androidx.core.content.ContextCompat;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.TextView;


public class ThirdActivity extends AppCompatActivity {

    private TextView mTextView;
    private ConstraintLayout mLayout;
    int Count=0;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_third);
        mTextView = findViewById(R.id.textView5);
        mLayout = findViewById(R.id.ConstraintLayout3);
    }
    public void onRed(View view) {
        if (Count==0){
            mTextView.setText(R.string.textRed);
            mLayout.setBackgroundColor(ContextCompat.getColor(getApplicationContext(),R.color.colorRed));
            Count+=1;}
    }

    public void onYellow(View view) {
        if (Count==1){
            mTextView.setText (R.string.textYellow);
            mLayout.setBackgroundColor(ContextCompat.getColor(getApplicationContext(),R.color.colorYellow));
            Count+=1;}
    }

    public void onGreen(View view) {
        if (Count==2){
            mTextView.setText (R.string.textGreen);
            mLayout.setBackgroundColor(ContextCompat.getColor(getApplicationContext(),R.color.colorGreen));
            Count=0;}
    }

    public void inSecondLayout(View view) {
        Intent intent = new Intent(ThirdActivity.this, SecondActivity.class);
        startActivity(intent);
    }

    public void onEndLayout(View view) {
        Intent intent = new Intent(ThirdActivity.this, EndActivity.class);
        intent.putExtra ("mTextView",mTextView.getText().toString());
        startActivity(intent);
    }
}

