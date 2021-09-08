# -*- coding: utf-8 -*-
"""
Created Jun 21

@author: jdclark905
"""


#import all our things
from selenium import webdriver
import time
import pandas as pd
import smtplib
from email.message import EmailMessage

def sendEmail(itemFoundList):
    """
    This will send the email notification that there are items on the list. 

    Returns
    -------
    None.

    """
	#email info removed, enter within strings
    emailSender = ''
    myThroaway = ''
    newEmail = ''
    emailRecipients = [myThroaway, newEmail]
    password = ""
    newEmail = """
    An item you were searching for is on Nellis Auction! 
    Go Check it out!
    The following Items were Found:
    {itemFoundList}
    
    """
    msg = EmailMessage()
    msg['subject'] = 'Nellis Auction Alerts'
    msg['from'] = emailSender
    msg['to'] = emailRecipients
    msg.set_content(newEmail.format(**locals()))

    with smtplib.SMTP_SSL('smtp.gmail.com', 465) as smtp:
        smtp.login(emailSender, password)
        smtp.send_message(msg)
    #end sendEmail()

#activate the driver
driver = webdriver.Edge(executable_path='C:\\Users\\jdcla\\Documents\\Python\\Nellis Auction Alerts\\msedgedriver.exe')

#we gotta grab all the auction numbers
mainURL = "https://www.nellisauction.com/"
# get web page
driver.get(mainURL)
# execute script to scroll down the page
driver.execute_script("window.scrollTo(0, document.body.scrollHeight);var lenOfPage=document.body.scrollHeight;return lenOfPage;")
print("Loading the Main page of Nellis Auction!")
# sleep for 5s
time.sleep(5)
#get all the auction numbers
results = driver.find_elements_by_partial_link_text('#')

#save the auction numbers
auctionNumbers = []
for i in results:
    #we're appending 1-5 here since these numbers seem to always be the start
    #high potential this could change so just flagging as a point to look at
    #numbers come in as a string to be used in the URL
    auctionNumbers.append(i.text[1:5])

#take out any duplicate values
auctionNumbers = list(dict.fromkeys(auctionNumbers))

titles = []

for aucNum in auctionNumbers:
    #we first need to grab each page count of the auction
    pageURL = "https://www.nellisauction.com/auction/" + aucNum + "/bidgallery/page_1/"
    # get web page
    driver.get(pageURL)
    # execute script to scroll down the page
    driver.execute_script("window.scrollTo(0, document.body.scrollHeight);var lenOfPage=document.body.scrollHeight;return lenOfPage;")
    # sleep for 5s
    print("Loading Auction # " + aucNum)
    time.sleep(5)
    result = driver.find_element_by_xpath("//*[@class='summary']")
    pageCount = int(result.text.split("of ")[1])
    print("The Page Count for Auction# " + aucNum + " is " + str(pageCount))
    for page in range(1, pageCount + 1):
        auctionPageURL = "https://www.nellisauction.com/auction/" + aucNum + "/bidgallery/page_" + str(page) + "/"
        driver.get(auctionPageURL)
        # execute script to scroll down the page
        driver.execute_script("window.scrollTo(0, document.body.scrollHeight);var lenOfPage=document.body.scrollHeight;return lenOfPage;")
        # sleep for 15s
        print("Loading Auction # " + aucNum + " currently on page " + str(page) + ".")
        time.sleep(5)
        results = driver.find_element_by_xpath("//*[@class='itemlist-wrapper']")
        temp = results.text.split("\n")
        for count, value in enumerate(temp):
            if 'Lot #' in value:
                titles.append(temp[count + 1])
    print("We currently found " + str(len(titles)) + " items so far!")

df = pd.DataFrame(titles)

searchList = ['rug', 'patio', 'blinds', 'sofa', 'couch', 'vanity']

foundTitles = []
for searchItem in searchList:
    for title in titles:
        if searchItem.upper() in title:
            foundTitles.append(title)
            break

sendEmail(foundTitles)
