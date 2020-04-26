import tweepy
import json
import csv
from datetime import date
from datetime import datetime
import time

tweet_id = 1244821561774923777

consumer_key = 'personal key'
consumer_secret = 'personal key secret'
access_token_key = 'personal token'
access_token_secret = 'personal token secret'
auth = tweepy.OAuthHandler(consumer_key, consumer_secret)
auth.set_access_token(access_token_key, access_token_secret)
api = tweepy.API(auth)
tweet = api.get_status(tweet_id)
