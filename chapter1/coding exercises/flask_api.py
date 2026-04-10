from flask import Flask as fk, request as rq, jsonify as web
from flask_cors import CORS as cors

app = fk(__name__)
cors(app)
@app.route("/predict", methods=["POST"])
def predict():
    data = rq.json
    result = data["x"] ** 2
    return web({"result": result})
if __name__ == "__main__":
    app.run(port=5000)
