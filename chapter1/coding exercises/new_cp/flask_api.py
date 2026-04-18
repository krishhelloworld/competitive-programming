from flask import Flask, request, jsonify
from flask_cors import CORS

app = Flask(__name__)
CORS(app, origins=["http://localhost:8501"])

@app.route('/home')
def hello():
    return jsonify(message="hello to my program")

@app.route("/predict", methods=["POST"])
def predict():
    data = request.get_json()
    result = data["x"] ** 2
    return jsonify(result=result)

if __name__ == "__main__":
    app.run(port=5000, debug=True)

# from flask import Flask, request, make_response

# app = Flask(__name__)

# # fake "database"
# users = {
#     "Aman": "1234"
# }

# # session store (VERY IMPORTANT)
# sessions = {}

# import uuid

# @app.route("/login", methods=["POST"])
# def login():
#     data = request.json
#     username = data["username"]
#     password = data["password"]

#     # check credentials
#     if username in users and users[username] == password:
#         session_id = str(uuid.uuid4())  # random session

#         # store session on server
#         sessions[session_id] = username

#         resp = make_response({"message": "login successful"})
#         resp.set_cookie("sessionid", session_id)

#         return resp

#     return {"message": "invalid credentials"}, 401


        # @app.route("/profile")
        # def profile():
        #     session_id = request.cookies.get("sessionid")

        #     # 🔥 THIS is where fake users are blocked
        #     if session_id not in sessions:
        #         return {"message": "unauthorized"}, 401

        #     user = sessions[session_id]
        #     return {"message": f"welcome {user}"}

# if __name__ == "__main__":
#     app.run(debug=True)