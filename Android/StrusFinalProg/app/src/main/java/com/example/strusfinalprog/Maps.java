package com.example.strusfinalprog;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;
import android.view.View;
import android.widget.EditText;
import android.widget.Toast;

public class Maps extends AppCompatActivity {

    private EditText name;

    String geoURI;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_maps);
        name = findViewById(R.id.name_map);
    }

    public void onHome(View view) {
        Intent intent = new Intent(this, MainActivity.class);
        Toast.makeText(getApplicationContext(),"Home",Toast.LENGTH_LONG).show();
        startActivity(intent);
        finish();
    }

    public void onSearchMap(View view) {
        geoURI = String.format("geo:0,0?q=" + name.getText().toString());
        Intent geoIntent = new Intent(Intent.ACTION_VIEW, Uri.parse(geoURI));
        name.setText(null);

        if (geoIntent.resolveActivity(getPackageManager()) != null) {
            startActivity(geoIntent);
        }
    }
}
