package com.example.mapsapp;

import androidx.appcompat.app.AlertDialog;
import androidx.appcompat.app.AppCompatActivity;

import android.content.DialogInterface;
import android.net.Uri;
import android.os.Bundle;
import android.content.Intent;
import android.view.View;
import android.widget.ImageView;
import android.widget.EditText;


public class MainActivity extends AppCompatActivity {

    private EditText lat;
    private EditText lon;
    private EditText name;
    private ImageView close;

    String geoURI;
    String geoUriString;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        lat = findViewById(R.id.latitude_map);
        lon = findViewById(R.id.longitude_map);
        name = findViewById(R.id.name_map);
        close = findViewById(R.id.closeButton);
    }

    public void onSearchMap(View view) {
        if (lat.getText().toString()!=null||lon.getText().toString()!=null)
        {
            geoURI = String.format("geo:%s,%s?z=15", lat.getText().toString(), lon.getText().toString());
        }
        else if (name.getText().toString()!=null)
        {
            geoURI = String.format("geo:0,0?q=" + name.getText().toString());
        }
        else
        {
            geoURI = String.format("geo:48.6745447,26.5662925?z=15");
        }

        Intent geoIntent = new Intent(Intent.ACTION_VIEW, Uri.parse(geoURI));
        lat.setText(null);
        lon.setText(null);
        name.setText(null);

        if (geoIntent.resolveActivity(getPackageManager()) != null) {
            startActivity(geoIntent);
        }
    }

    public void onSearchView(View view) {
        if (lat.getText().toString()!=null||lon.getText().toString()!=null)
        {
            geoUriString = String.format("google.streetview:cbll=%s,%s&cbp=1,99.56,,1,2.0&mz=19", lat.getText().toString(),lon.getText().toString());
        }

        else
        {
            geoUriString = String.format("google.streetview:cbll=59.939448,30.328264&cbp=1,99.56,,1,2.0&mz=19");
        }

        Intent mapIntent = new Intent(Intent.ACTION_VIEW, Uri.parse(geoUriString));
        lat.setText(null);
        lon.setText(null);
        name.setText(null);

        if (mapIntent.resolveActivity(getPackageManager()) != null) {
            startActivity(mapIntent);
        }
    }

    public void onClose(View view) {
        AlertDialog.Builder builder = new AlertDialog.Builder(this);
        builder.setMessage("Are you sure you want to exit?")
                .setCancelable(false)
                .setPositiveButton("Yes", new DialogInterface.OnClickListener() {
                    public void onClick(DialogInterface dialog, int id) {
                        MainActivity.this.finish();
                    }
                })
                .setNegativeButton("No", new DialogInterface.OnClickListener() {
                    public void onClick(DialogInterface dialog, int id) {
                        dialog.cancel();
                    }
                });
        AlertDialog alert = builder.create();
        alert.show();
    }
}