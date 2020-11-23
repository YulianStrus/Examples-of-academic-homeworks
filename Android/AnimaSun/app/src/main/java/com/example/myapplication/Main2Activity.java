package com.example.myapplication;

import android.os.Bundle;
import android.view.View;
import android.widget.EditText;
import android.widget.TextView;

import androidx.appcompat.app.AppCompatActivity;

import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import java.io.IOException;

import okhttp3.Call;
import okhttp3.Callback;
import okhttp3.OkHttpClient;
import okhttp3.Request;
import okhttp3.Response;

public class Main2Activity extends AppCompatActivity {

    private TextView mTextViewResult;

    double usdToUah = 0;
    double eurToUah = 0;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main2);
        mTextViewResult = findViewById(R.id.text_view_result);
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
                    try {
                            text += myarr.getJSONObject(0).getString("ccy") + " Buy:";
                            text += myarr.getJSONObject(0).getString("buy") + " Sale:";
                            text += myarr.getJSONObject(0).getString("sale") + " \n";
                        usdToUah = myarr.getJSONObject(0).getDouble("buy");
                    } catch (JSONException e) {
                        e.printStackTrace();
                    }
                    final String finalText = text;
                    Main2Activity.this.runOnUiThread(new Runnable() {
                        @Override
                        public void run() {
                            mTextViewResult.setText(finalText);
                        }
                    });
                }
            }
        });
    }

    public void convertCurrency(View view) {
        EditText count = findViewById(R.id.editText2);
        TextView mytext = findViewById(R.id.textView);
        mytext.setText(String.valueOf(usdToUah * Double. valueOf(count.getText().toString())));
    }
}