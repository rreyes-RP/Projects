import PySimpleGUI as sg
import mysql.connector
import pandas as pd
import os

# Define the GUI window
sg.theme('SandyBeach')
layout = [
    [sg.Text('Please enter SQL')],
    [sg.Multiline(size=(50,5), key = 'textbox')],
    [sg.Submit(), sg.Cancel()]
]
window = sg.Window('Report Generator', layout)
event, values = window.read()
query = values['textbox']

# SQL Connection/Query
cnx = mysql.connector.connect(
            host=host_name,
            user=user_name,
            passwd=user_password,
            database=db_name
)

# Create and Open report
df = pd.read_sql(query, cnx)
df.to_excel('report.xlsx', index=False)
os.startfile('report.xlsx')
