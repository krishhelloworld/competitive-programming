import streamlit as st

# Title
st.title("My First Streamlit App")

# Text
st.write("Hello! This is a simple Streamlit app.")

# User input
name = st.text_input("Enter your name:")

# Button
if st.button("Greet"):
    if name:
        st.success(f"Hello, {name}! 👋")
    else:
        st.warning("Please enter your name.")

# Slider
age = st.slider("Select your age:", 1, 100, 25)
st.write(f"You are {age} years old.")