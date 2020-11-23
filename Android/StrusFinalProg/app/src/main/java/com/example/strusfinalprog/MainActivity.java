package com.example.strusfinalprog;

import androidx.appcompat.app.AlertDialog;
import androidx.appcompat.app.AppCompatActivity;

import android.content.DialogInterface;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }


    public void onTextEd(View view) {
        Intent intent = new Intent(this, TextEditor.class);
        startActivity(intent);
    }

    public void onConvert(View view) {
        Intent intent = new Intent(MainActivity.this, Converter.class);
        startActivity(intent);
    }

    public void onMaps(View view) {
        Intent intent = new Intent(MainActivity.this, Maps.class);
        startActivity(intent);
    }

    public void onClose(View view) {
        AlertDialog.Builder builder = new AlertDialog.Builder(this);
        builder.setMessage("Are you sure you want to exit?")
                .setCancelable(false)
                .setPositiveButton("Yes", new DialogInterface.OnClickListener() {
                    public void onClick(DialogInterface dialog, int id) {MainActivity.this.finish();
                    }
                })
                .setNegativeButton("No", new DialogInterface.OnClickListener() {
                    public void onClick(DialogInterface dialog, int id) {dialog.cancel();
                    }
                });
        AlertDialog alert = builder.create();
        alert.show();
    }
}
