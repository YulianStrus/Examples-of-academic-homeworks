package ua.kugaievskyi.groupssplit;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.EditText;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }

    public void OnClick(View view) {

        EditText drawField = findViewById(R.id.fieldDraw);
        EditText numberField = findViewById(R.id.fieldNumber);

        String[] arrayStr = drawField.getText().toString().split("\n");
        int number = Integer.parseInt(numberField.getText().toString());

        if(number > arrayStr.length){
            Toast toast = Toast.makeText(getApplicationContext(),"Кількість учасників в групі має бути менша, ніж загальна кількість учасників ",Toast.LENGTH_LONG);
            toast.show();
        }
        else {
            Intent intent = new Intent(MainActivity.this, GroupActivity.class);
            intent.putExtra("drawField", drawField.getText().toString());
            intent.putExtra("numberField", numberField.getText().toString());

            startActivity(intent);
        }
    }
}
