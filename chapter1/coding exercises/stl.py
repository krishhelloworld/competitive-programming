import streamlit as st
import pandas as pd
import requests as rqs
from sklearn.datasets import load_iris   
from sklearn.ensemble import RandomForestClassifier   
import webbrowser as wb
# Title
st.set_page_config(
    page_title="Stock peer analysis dashboard",
    page_icon=":chart_with_upwards_trend:",
    layout="wide",
)

"""
# :material/query_stats: Stock peer analysis

`Easily compare stocks against others in their peer group.`
"""


url = "www.google.com"
st.markdown(
    """<style> 
    .cst{
        color: purple;
    font-size: 24px;
    font-weight: bold;
}

.url{
color:red;
}
    </style>""",unsafe_allow_html=True
)
if wb.open(url):
    st.markdown(f'<p class = "cst" ><h1> opened <span class = "url"> {url}</span> successfully</h1></p>',unsafe_allow_html=True)

# DEFAULT_STOCKS = ["AAPL", "GOOG", "MSFT"]

# # Utility function to convert list to comma-separated string
# def stocks_to_str(stocks_list):
#     return ",".join(stocks_list)

# # Initialize session state for tickers
# if "tickers_input" not in st.session_state:
#     st.session_state.tickers_input = st.query_params.get(
#         "stocks", stocks_to_str(DEFAULT_STOCKS)
#     ).split(",")

# st.title("Stock Ticker App")
# st.write("Current tickers:", st.session_state.tickers_input)

# new_tickers = st.text_input(
#     "Enter tickers (comma-separated):", 
#     value=stocks_to_str(st.session_state.tickers_input)
# )

# # Update session state when input changes
# if st.button("Update Tickers"):
#     st.session_state.tickers_input = [t.strip().upper() for t in new_tickers.split(",")]
#     st.experimental_rerun()  # rerun app to reflect changes

# st.write("Updated tickers:", st.session_state.tickers_input)
