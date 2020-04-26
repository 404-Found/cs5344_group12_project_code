import tweepy
import json
import csv
from datetime import date
from datetime import datetime
import time

tweet_id = 1244821561774923777

consumer_key = 'arwHbnZrAKmRKF6S2OWuZANCR'
consumer_secret = 'uTsSIYNUWtzGbn0JAEJEDepQ0PeN6odxzzjoqY7uKNolRFkYBc'
access_token_key = '513983265-pTX3zHztDOID6kS0VOvLSNabaz8EUBEaSEX0qB7q'
access_token_secret = 'gKSb9dJ1KDodldNiYJvlNRCk014b5Vhjd76ctBEGebelT'
auth = tweepy.OAuthHandler(consumer_key, consumer_secret)
auth.set_access_token(access_token_key, access_token_secret)
api = tweepy.API(auth)
tweet = api.get_status(tweet_id)