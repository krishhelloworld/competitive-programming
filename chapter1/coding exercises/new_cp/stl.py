import streamlit as st
import requests

st.title("Square Calculator")

url = "http://127.0.0.1:5000"

num = st.number_input("Enter a number", value=0)

if st.button("Calculate Square"):

    try:
        # GET request
        home_response = requests.get(f"{url}/home"  )

        if home_response.status_code == 200:
            st.write( home_response.json()["message"])
        else :
            print("something is very wrong above")
        # POST request
        response = requests.post(
            f"{url}/predict",
            json={"x": num}
        )

        if response.status_code==200:
            result = response.json()["result"]
            st.success(f"Square is: {result}")
        else:
            st.error("Error from backend")

    except Exception as e:
        st.error(f"Connection error: {e}")