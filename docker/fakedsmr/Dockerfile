# Use an official Python runtime as a parent image
FROM python:3.9-slim

# Set the working directory in the container
WORKDIR /usr/src/fakedsmr

# Copy the fakedsmr script into the container at /usr/src/fakedsmr
COPY fakedsmr.py .

# Install requirements for mqtt
RUN pip install --no-cache-dir paho-mqtt

# Make port 80 available to the world outside this container
EXPOSE 80

# Run mqtt_mock.py when the container launches
CMD ["python", "./fakedsmr.py"]
