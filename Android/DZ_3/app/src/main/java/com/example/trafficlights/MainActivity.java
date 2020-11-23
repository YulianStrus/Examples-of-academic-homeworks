package com.example.trafficlights;

import androidx.appcompat.app.AppCompatActivity;
import androidx.constraintlayout.widget.ConstraintLayout;
import androidx.core.content.ContextCompat;

import android.os.Bundle;
import android.view.View;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    private TextView mTextView;
    private ConstraintLayout mLayout;
    int Count=0;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        mTextView = findViewById(R.id.textView);
        mLayout = findViewById(R.id.colorBackground);
    }

    public void onRed(View view) {
        if (Count==0){
        mTextView.setText (R.string.text_red);
        mLayout.setBackgroundColor(ContextCompat.getColor(getApplicationContext(),R.color.colorRed));
        Count+=1;}
    }

    public void onYellow(View view) {
        if (Count==1){
        mTextView.setText (R.string.text_yellow);
        mLayout.setBackgroundColor(ContextCompat.getColor(getApplicationContext(),R.color.colorYellow));
        Count+=1;}
    }

    public void onGreen(View view) {
        if (Count==2){
        mTextView.setText (R.string.text_green);
        mLayout.setBackgroundColor(ContextCompat.getColor(getApplicationContext(),R.color.colorGreen));
        Count=0;}
    }
}
