package com.example.popapmenu;

import androidx.appcompat.app.AppCompatActivity;
import androidx.constraintlayout.widget.ConstraintLayout;
import androidx.core.content.ContextCompat;
import android.os.Bundle;
import android.widget.PopupMenu;
import android.view.MenuItem;
import android.view.View;
import android.widget.Button;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    private ConstraintLayout mLayout;

    public MainActivity() {
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Button button = findViewById(R.id.button);
        mLayout = findViewById(R.id.colorBackground);
        button.setOnClickListener(viewClickListener);
    }

    View.OnClickListener viewClickListener = new View.OnClickListener() {
        @Override
        public void onClick(View v) {
            showPopupMenu(v);
        }
    };

    private void showPopupMenu(View v) {
        PopupMenu popupMenu = new PopupMenu(this, v);
        popupMenu.inflate(R.menu.popupmenu);

        popupMenu
                .setOnMenuItemClickListener(new PopupMenu.OnMenuItemClickListener() {
                    @Override
                    public boolean onMenuItemClick(MenuItem item) {
                        switch (item.getItemId()) {
            case R.id.menu1:
                Toast.makeText(getApplicationContext(), "Stop", Toast.LENGTH_SHORT).show();
                mLayout.setBackgroundColor(ContextCompat.getColor(getApplicationContext(),R.color.colorRed));
                return true;
            case R.id.menu2:
                Toast.makeText(getApplicationContext(), "Ready", Toast.LENGTH_SHORT).show();
                mLayout.setBackgroundColor(ContextCompat.getColor(getApplicationContext(),R.color.colorYellow));
                return true;
            case R.id.menu3:
                Toast.makeText(getApplicationContext(),"Go", Toast.LENGTH_SHORT).show();
                mLayout.setBackgroundColor(ContextCompat.getColor(getApplicationContext(),R.color.colorGreen));
                return true;
                            default:
                                return false;
                        }
                    }
                });

        /*popupMenu.setOnDismissListener(new PopupMenu.OnDismissListener() {
            @Override
            public void onDismiss(PopupMenu menu) {
                Toast.makeText(getApplicationContext(), "onDismiss",
                        Toast.LENGTH_SHORT).show();
            }
        });*/
        popupMenu.show();
    }
}