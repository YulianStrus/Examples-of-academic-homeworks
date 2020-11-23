package com.example.hellokitty;

import androidx.appcompat.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.TextView;
import android.widget.EditText;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    private TextView mTextView;
    private EditText mEditText;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        mEditText = findViewById(R.id.editText);
        mTextView = findViewById(R.id.textView);
    }


    public void onclick(View view) {
        mTextView.setText("Hello my name is " + mEditText.getText());
        Toast toast = Toast.makeText(getApplicationContext(), "Text", Toast.LENGTH_SHORT);
        toast.show();
    }
}
