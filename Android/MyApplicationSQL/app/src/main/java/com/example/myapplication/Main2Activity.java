package com.example.myapplication;
import androidx.appcompat.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.EditText;
import android.widget.RadioGroup;
import android.widget.TextView;

import org.json.JSONArray;
import org.json.JSONException;

import java.io.IOException;
import okhttp3.Call;
import okhttp3.Callback;
import okhttp3.OkHttpClient;
import okhttp3.Request;
import okhttp3.Response;

public class Main2Activity extends AppCompatActivity {

    private TextView mTextViewUsd;
    private TextView mTextViewEur;
    private TextView mTextViewRub;
    private TextView mTextViewRes;
    private EditText mEditText;
    double usdS = 0;
    double usdB = 0;
    double eurS = 0;
    double eurB = 0;
    double rubS = 0;
    double rubB = 0;
    double valB = 0;
    double valS = 0;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main2);
        mTextViewUsd = findViewById(R.id.textViewUsd);
        mTextViewEur = findViewById(R.id.textViewEur);
        mTextViewRub = findViewById(R.id.textViewRub);
        mTextViewRes = findViewById(R.id.textView);
        mEditText = findViewById(R.id.editTextNum);
        RadioGroup radioGroup = (RadioGroup) findViewById(R.id.radioGroup);
        OkHttpClient client = new OkHttpClient();
        String url = "https://api.privatbank.ua/p24api/pubinfo?exchange&json&coursid=11";

        Request request = new Request.Builder()
                .url(url)
                .build();

        client.newCall(request).enqueue(new Callback() {
            @Override
            public void onFailure(Call call, IOException e) {
                e.printStackTrace();
            }
            @Override
            public void onResponse(Call call, Response response) throws IOException {
                if (response.isSuccessful()) {
                    String myResponse = response.body().string();
                    JSONArray myarr = null;
                    try {
                        myarr = new JSONArray(myResponse);
                    } catch (JSONException e) {
                        e.printStackTrace();
                    }
                    String text = "";
                    String textEur = "";
                    String textUsd = "";
                    String textRub = "";
                    try {
                        for (int i=0; i<3; i++){
                        text+= myarr.getJSONObject(i).getString("ccy") + "\n";
                        text+= myarr.getJSONObject(i).getString("buy") + "\n";
                        text+= myarr.getJSONObject(i).getString("sale") + "\n";
                        if (i==0)
                        {
                            textUsd = text;
                            usdB=myarr.getJSONObject(i).getDouble("buy");
                            usdS=myarr.getJSONObject(i).getDouble("sale");
                            text = "";
                        }
                        else if (i==1)
                        {
                            textEur = text;
                            eurB=myarr.getJSONObject(i).getDouble("buy");
                            eurS=myarr.getJSONObject(i).getDouble("sale");
                            text = "";
                        }
                        else
                        {
                            textRub = text;
                            rubB=myarr.getJSONObject(i).getDouble("buy");
                            rubS=myarr.getJSONObject(i).getDouble("sale");
                            text = "";
                        }
                        }
                    } catch (JSONException e) {
                        e.printStackTrace();
                    }
                    final String finalTextUsd = textUsd;
                    final String finalTextEur = textEur;
                    final String finalTextRub = textRub;
                    Main2Activity.this.runOnUiThread(new Runnable() {
                        @Override
                        public void run() {
                            mTextViewEur.setText(finalTextEur);
                        }
                    });
                    Main2Activity.this.runOnUiThread(new Runnable() {
                        @Override
                        public void run() {
                            mTextViewUsd.setText(finalTextUsd);
                        }
                    });
                    Main2Activity.this.runOnUiThread(new Runnable() {
                        @Override
                        public void run() {
                            mTextViewRub.setText(finalTextRub);
                        }
                    });

                }
            }
        });
        radioGroup.clearCheck();

        radioGroup.setOnCheckedChangeListener(new RadioGroup.OnCheckedChangeListener() {

            @Override
            public void onCheckedChanged(RadioGroup group, int checkedId) {
                switch (checkedId) {
                    case -1:
                        mTextViewRes.setText("");
                        break;
                    case R.id.radioUsd:
                        valB=usdB;
                        valS=usdS;
                        break;
                    case R.id.radioEur:
                        valB=eurB;
                        valS=eurS;
                        break;
                    case R.id.radioRub:
                        valB=rubB;
                        valS=rubS;
                        break;
                }
            }
        });
    }


    public void onBuy(View view) {
        mTextViewRes.setText(String.valueOf(valB * Double.valueOf(mEditText.getText().toString())));
    }

    public void onSelling(View view) {
        mTextViewRes.setText(String.valueOf(valS * Double.valueOf(mEditText.getText().toString())));
    }
}