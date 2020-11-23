package com.example.animalsound;

import android.annotation.TargetApi;
import android.content.res.AssetFileDescriptor;
import android.content.res.AssetManager;
import android.media.AudioAttributes;
import android.media.AudioManager;
import android.media.SoundPool;
import android.os.Build;
import android.os.Bundle;
import android.view.View;
import android.widget.ImageButton;
import android.widget.Toast;
import androidx.appcompat.app.AppCompatActivity;

import java.io.IOException;

public class MainActivity extends AppCompatActivity {

    private SoundPool mSoundPool;
    private AssetManager mAssetManager;
    private int mCatSound, mChickenSound, mCowSound, mDogSound, mDuckSound, mSheepSound;
    private int mStreamID;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        if(Build.VERSION.SDK_INT < Build.VERSION_CODES.LOLLIPOP)
            createOldSoundPool();
        else
            createNewSoundPool();

        mAssetManager = getAssets();

        mCatSound = loadSound("cat.mp3");
        mChickenSound = loadSound("chicken.mp3");
        mCowSound = loadSound("cow.wav");
        mDogSound = loadSound("dog.wav");
        mDuckSound = loadSound("duck.mp3");
        mSheepSound = loadSound("sheep.wav");

        ImageButton catImageButton = findViewById(R.id.imageButtonCat);
        catImageButton.setOnClickListener(onClickListener);

        ImageButton chickenImageButton = findViewById(R.id.imageButtonChicken);
        chickenImageButton.setOnClickListener(onClickListener);

        ImageButton cowImageButton = findViewById(R.id.imageButtonCow);
        cowImageButton.setOnClickListener(onClickListener);

        ImageButton dogImageButton = findViewById(R.id.imageButtonDog);
        dogImageButton.setOnClickListener(onClickListener);

        ImageButton duckImageButton = findViewById(R.id.imageButtonDuck);
        duckImageButton.setOnClickListener(onClickListener);

        ImageButton sheepImageButton = findViewById(R.id.imageButtonSheep);
        sheepImageButton.setOnClickListener(onClickListener);
    }

    @SuppressWarnings("deprecation")
    private void createOldSoundPool(){
        mSoundPool = new SoundPool(3, AudioManager.STREAM_MUSIC,0);
    }

    @TargetApi(Build.VERSION_CODES.LOLLIPOP)
    private void createNewSoundPool(){
        AudioAttributes attributes = new AudioAttributes.Builder().setUsage(AudioAttributes.USAGE_GAME).setContentType(AudioAttributes.CONTENT_TYPE_SONIFICATION).build();
        mSoundPool = new SoundPool.Builder().setAudioAttributes(attributes).build();
    }

    private int loadSound(String fileName){
        AssetFileDescriptor afd;
        try{
            afd = mAssetManager.openFd(fileName);
        }
        catch (IOException e){
            e.printStackTrace();
            Toast.makeText(getApplicationContext(), "Не вдається завантажити файл " + fileName, Toast.LENGTH_SHORT).show();
            return -1;
        }
        return mSoundPool.load(afd,1);
    }

    private int playSound(int sound){
        if(sound > 0)
            mStreamID = mSoundPool.play(sound,1,1,1,0,1);
        return mStreamID;
    }

    View.OnClickListener onClickListener = new View.OnClickListener() {
        @Override
        public void onClick(View v) {
            switch (v.getId()){
                case R.id.imageButtonCat:
                    playSound(mCatSound);
                    break;
                case R.id.imageButtonChicken:
                    playSound(mChickenSound);
                    break;
                case R.id.imageButtonCow:
                    playSound(mCowSound);
                    break;
                case R.id.imageButtonDog:
                    playSound(mDogSound);
                    break;
                case R.id.imageButtonDuck:
                    playSound(mDuckSound);
                    break;
                case R.id.imageButtonSheep:
                    playSound(mSheepSound);
                    break;
            }
        }
    };

    @Override
    protected void onResume(){
        super.onResume();

        if(Build.VERSION.SDK_INT < Build.VERSION_CODES.LOLLIPOP)
            createOldSoundPool();
        else
            createNewSoundPool();

        mAssetManager = getAssets();

        mCatSound = loadSound("cat.mp3");
        mChickenSound = loadSound("chicken.mp3");
        mCowSound = loadSound("cow.mp3");
        mDogSound = loadSound("dog.mp3");
        mDuckSound = loadSound("duck.mp3");
        mSheepSound = loadSound("sheep.mp3");
    }

    @Override
    protected  void onPause(){
        super.onPause();

        mSoundPool.release();
        mSoundPool = null;
    }
}

