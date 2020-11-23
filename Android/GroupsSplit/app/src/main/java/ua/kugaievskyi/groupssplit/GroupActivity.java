package ua.kugaievskyi.groupssplit;

import androidx.appcompat.app.AppCompatActivity;
import androidx.core.content.ContextCompat;

import android.content.Context;
import android.content.res.Resources;
import android.graphics.Color;
import android.os.Bundle;
import android.util.DisplayMetrics;
import android.util.Log;
import android.view.Gravity;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.LinearLayout;
import android.widget.TextView;
import android.widget.Toast;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class GroupActivity extends AppCompatActivity {

    String drawField;
    int number;

//    public static int convertPixelsToDp(float px, Context context){
//        Resources resources = context.getResources();
//        DisplayMetrics metrics = resources.getDisplayMetrics();
//        int dp = (int)(px / (metrics.densityDpi / 160f));
//        return dp;
//    }

    public static int dpToPx(int dp)
    {
        return (int) (dp * Resources.getSystem().getDisplayMetrics().density);
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_group);

        drawField = getIntent().getExtras().getString("drawField");
        number = Integer.parseInt(getIntent().getExtras().getString("numberField"));

        String[] arrayStr = drawField.split("\n");
        int numberGroup = (int)Math.ceil((double) arrayStr.length/number);

        LinearLayout linearLayout = findViewById(R.id.linearLayout);
        ArrayList<EditText> EditTextList = new ArrayList<EditText>();

        LinearLayout.LayoutParams lparams = new LinearLayout.LayoutParams(dpToPx(250),dpToPx(20*number+30));
        lparams.gravity = Gravity.CENTER_HORIZONTAL;
        lparams.setMargins(0,dpToPx(20),0,dpToPx(30));

        for(int i = 0;i < numberGroup; i++){
            EditText editText = new EditText(getApplicationContext());

            editText.setBackgroundDrawable(ContextCompat.getDrawable(getApplicationContext(),R.drawable.bg));
            editText.setLayoutParams(lparams);
            editText.setPadding(dpToPx(10),dpToPx(10),dpToPx(10),dpToPx(10));
            EditTextList.add(editText);
        }

        int count = 0;
        List list = Arrays.asList(arrayStr);
        ArrayList<String> tempArrayStr = new ArrayList<String>(list);

        for(int i=0;i<arrayStr.length;++i){
            int numb = (int)(Math.random() * (tempArrayStr.size() - 1));
            EditTextList.get(count).append(tempArrayStr.get(numb));
            if(i < arrayStr.length-numberGroup)
                EditTextList.get(count).append("\n");
            tempArrayStr.remove(numb);
            if(count == numberGroup-1)
                count=0;
            else
                count++;
        }

        LinearLayout.LayoutParams params = new LinearLayout.LayoutParams(LinearLayout.LayoutParams.WRAP_CONTENT, LinearLayout.LayoutParams.WRAP_CONTENT);
        params.gravity = Gravity.CENTER_HORIZONTAL;

        for(int i = 0;i < numberGroup; i++) {
            TextView textView = new TextView(getApplicationContext());
            textView.setText("Група №" + (i+1));
            textView.setTextColor(Color.WHITE);
            textView.setTextSize(24);
            textView.setLayoutParams(params);
            linearLayout.addView(textView);

            linearLayout.addView(EditTextList.get(i));


        }

//                Toast toast = Toast.makeText(getApplicationContext(), Integer.toString(numberGroup), Toast.LENGTH_SHORT);
//        toast.show();

    }


}
