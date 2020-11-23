package com.example.countcrow;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    private TextView mTextView;
    private Integer crown=1;
    private Integer cat=1;
    private Integer dog=1;
    private Integer man=1;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        mTextView = findViewById(R.id.textView);
    }

    public void addCrown(View view) {
    crown = crown + 1;
    mTextView.setText("Ворон: " + crown);
    }

    public void addCat(View view) {
        if (crown>0){
        cat = cat +1;
        crown = crown - 1;
        mTextView.setText("Ворон: " + crown + "\nКотів: " + cat);}
        else mTextView.setText("Із-за відсутності ворон коти пішли шукати мишей!");
    }

    public void addDog(View view) {
        if (cat>0){
        dog = dog +1;
        cat = cat - 1;
        mTextView.setText("Ворон: " + crown + "\nКотів: " + cat + "\nСобак: " + dog);}
        else mTextView.setText("Із-за відсутності котів собаки пішли спати)");
    }

    public void addMan(View view) {
        if (dog>0){
        man = man +1;
        dog = dog - 1;
        mTextView.setText("Ворон: " + crown + "\nКотів: " + cat + "\nСобак: " + dog+ "\nКорейців: " + man);}
        else if (cat>0) {
            man = man +1;
        cat = cat - 1;
        mTextView.setText("Ворон: " + crown + "\nКотів: " + cat + "\nСобак: " + dog+ "\nКорейців: " + man);}
        else if (crown>0) {
            man = man +1;
            crown = crown - 1;
            mTextView.setText("Ворон: " + crown + "\nКотів: " + cat + "\nСобак: " + dog+ "\nКорейців: " + man);}
        else mTextView.setText("Із-за відсутності їжі вимерла нація)");
    }
}
