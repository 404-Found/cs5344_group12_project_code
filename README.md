# CS5344 Group 12 Project Codes
Codes for Group 12 term project, Sentiment Analysis on Tweets, in AY19/20 SEM2, for course CS5344 NUS.

We consolidate all of our codes used in term project in this respository. The structure of our project is:


**Part 1 : Data Collection and Preparation**
We collected data from two datasource: 1) labeled sentiment data from IEEE for model training 2) scrapping raw tweets from twitter (via tweepy) for prediction, and then perform data clearning and processing in prepare of training model and analyze result. 

**Part 2: Model Training and Optimization**
We employed 4 different models to categorize tweets sentiment and then predict the sentiment for un-seen tweets.

**Part 3: Result Analysis**
After we determined the best model for this task, which is Transfer Learning with GloVe, we utilise this model to predict sentiment for tweets and classify them into 'Positive', 'Negative' and 'Neutral' for analysis. 

In this repository, we have codes for :
- Code 1. Scrapping Data From Twitter

- Code 2. Main Code for Models
  -> Due to the large size of GloVe vector, please refer here for the source: https://drive.google.com/file/d/1gV8Jf-FaSBg9Gsk6WziiCmfYpjEdOCdc/view
  
- Code 3. Classification on Sentiment and Result Analysis

PS: Please note that due to different running environment from each teammate, the code may not succesfully run-able in all all environment. Please contact individual author if you have questions. 

Contributors:
K.Chen, S.Liu, S.Shen, X.Zhang, Z.Wang
