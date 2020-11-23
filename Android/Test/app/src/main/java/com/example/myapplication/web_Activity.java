package com.example.myapplication;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.widget.TextView;

import org.jetbrains.annotations.NotNull;

import java.io.IOException;

import okhttp3.Call;
import okhttp3.Callback;
import okhttp3.OkHttpClient;
import okhttp3.Request;
import okhttp3.Response;

public class web_Activity extends AppCompatActivity {

    private TextView mTextResult;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_web_);
        mTextResult = findViewById(R.id.textView);

        OkHttpClient client = new OkHttpClient();

        String url = "https://api.privatbank.ua/p24api/pubinfo?json&exchange&coursid=5";

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
                                                    if(response.isSuccessful()){
                                                        final String myResponse = response.body().string();

                                                        web_Activity.this.runOnUiThread(new Runnable() {
                                                            @Override
                                                            public void run() {
                                                                mTextResult.setText(myResponse);
                                                            }
                                                        });
                                                    }
                                            }
                                        }
        );
    }
}
