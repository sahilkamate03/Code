from flask import Flask, jsonify, request

app =Flask(__name__)

@app.route('/api', methods =['GET'])
def api():
    if (request.method == 'GET'):
        data ="Hello, Sahil"

        return jsonify({'data':data})
    
if __name__ == '__main__':
    app.run(debug=True)