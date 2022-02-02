#import all our things
from selenium import webdriver
import time
import smtplib
from email.message import EmailMessage
import random

def sendEmail(itemFoundList):
    """
    This will send the email notification that there are items on the list. 

    Returns
    -------
    None.

    """
    emailSender = ''
    myThroaway = ''
    newEmail = ''
    emailRecipients = [myThroaway]
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
mainURL = "https://www.nellisauction.com/search"
# get web page
driver.get(mainURL)
# execute script to scroll down the page
driver.execute_script("window.scrollTo(0, document.body.scrollHeight);var lenOfPage=document.body.scrollHeight;return lenOfPage;")
print("Loading the Main page of Nellis Auction!")
# sleep for abit
time.sleep(5)

#first we need to find out how many pages we need to go through
#//p choosen because that is the element of the page identifier
results = driver.find_elements_by_xpath("//p")

#there usually is only one line with the pages, so let's find it
pageString = ""
for i in results:
    if "Pages" in i.text:
        print(i.text)
        pageString = i.text

#now to pull out the numbers
pageCount = int(pageString.split( )[0])

#now let's loop through the search pages
pageRunner = 1
titles = []
while pageRunner < pageCount + 1:
    pageURL = "https://www.nellisauction.com/search?page=" + str(pageRunner)
    driver.get(pageURL)
    driver.execute_script("window.scrollTo(0, document.body.scrollHeight);var lenOfPage=document.body.scrollHeight;return lenOfPage;")
    time.sleep(random.randint(3,9))
    results = driver.find_elements_by_xpath("//h2")
    for i in results:
        titles.append(i.text)
    pageRunner += 1

searchList = ['rug', 'patio', 'blinds', 'sofa', 'couch', 'vanity', 'concrete']

foundTitles = []
for searchItem in searchList:
    for title in titles:
        if searchItem.upper() in title.upper():
            foundTitles.append(title)
            break

sendEmail(foundTitles)
