package com.example.transition;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Toast;

public class EndActivity extends AppCompatActivity {

    private String colorText;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_end);
        colorText = getIntent().getStringExtra("mTextView");
    }

    public void ToastClick(View view) {
        Toast toast = Toast.makeText(getApplicationContext(), colorText, Toast.LENGTH_SHORT);
        toast.show();
    }

    public void inThirdLayout(View view) {
        Intent intent = new Intent(EndActivity.this, ThirdActivity.class);
        startActivity(intent);
        finish();
    }
}
