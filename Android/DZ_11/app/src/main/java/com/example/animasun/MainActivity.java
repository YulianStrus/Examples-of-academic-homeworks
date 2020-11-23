package com.example.animasun;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.view.animation.Animation;
import android.view.animation.AnimationUtils;
import android.widget.ImageView;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    private ImageView sunImageView;
    private ImageView clockImageView;
    private ImageView hourImageView;
    boolean sun = false;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);


        sunImageView = (ImageView) findViewById(R.id.sun);
        clockImageView = (ImageView) findViewById(R.id.clock);
        hourImageView = (ImageView) findViewById(R.id.hour_hand);
    }

    public void onSunSet(View view) {
        if (sun==true)
        {
            Animation sunSetAnimation = AnimationUtils.loadAnimation(this, R.anim.sun_set);
            sunImageView.startAnimation(sunSetAnimation);
            Animation clockTurnAnimation = AnimationUtils.loadAnimation(this, R.anim.clock_turn);
            clockImageView.startAnimation(clockTurnAnimation);
            Animation hourTurnAnimation = AnimationUtils.loadAnimation(this, R.anim.hour_turn);
            hourImageView.startAnimation(hourTurnAnimation);
            sun=false;
        }
        else
        {
            Animation sunRiseAnimation = AnimationUtils.loadAnimation(this, R.anim.sun_rise);
            sunImageView.startAnimation(sunRiseAnimation);
            Animation clockTurnAnimation = AnimationUtils.loadAnimation(this, R.anim.clock_on);
            clockImageView.startAnimation(clockTurnAnimation);
            Animation hourTurnAnimation = AnimationUtils.loadAnimation(this, R.anim.hour_on);
            hourImageView.startAnimation(hourTurnAnimation);
            sun=true;
        }
    }
}

