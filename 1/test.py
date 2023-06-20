import pandas as pd
import numpy as np
from bs4 import BeautifulSoup
import requests
import string

def data_extration(url_id,url):
    html_text=requests.get(url).text
    soup = BeautifulSoup(html_text,'lxml')
    page_header = soup.title.string
    if "not found" in page_header:
        content = 'Page not found '
    else:
        content = soup.findAll(attrs={'class':'td-post-content'})    
        content = content[0].text    
        content = content.translate(str.maketrans('', '', string.punctuation))
        
    file_content = page_header+'\n \n'+content
    with open(f'output\{url_id}.txt','w',encoding="utf-8",) as f:
        f.write(file_content)

input_data = pd.read_excel("Input.xlsx")

for i in range(len(input_data)):
    print(input_data['URL_ID'][i])
    data_extration(input_data['URL_ID'][i],input_data['URL'][i])