# Dynamic Public Transport Route Optimizer

## Overview

The Dynamic Public Transport Route Optimizer is a system that computes the fastest public transport route between any two points in a city by intelligently combining buses, metro lines, and walking paths.

Unlike traditional transport systems with fixed routes, this project dynamically calculates the most efficient path using graph algorithms and provides an interactive frontend with map visualization.

## Problem Statement

Public transport systems are usually static and optimized independently for buses or metros. However, commuters need the fastest possible route, regardless of transport mode.

This project addresses the following issues:
- Lack of integration between multiple transport modes
- No real-time route optimization
- Time loss due to indirect or rigid routes

## What the Project Does

- Accepts user input for starting and ending locations
- Constructs a weighted graph representing buses, metros, and walkable paths
- Applies Dijkstra’s algorithm to compute the fastest travel route
- Combines different modes of transport dynamically in a single trip
- Displays live routes and multiple options using a React-based map UI

## Technologies Used

### Backend
- C++: Core algorithm and logic
- Dijkstra’s Algorithm: Used for route optimization
- CSV/JSON: For data storage and parsing
- Node.js / Express (optional): API interface for frontend communication

### Frontend
- React.js: User interface
- Leaflet / Google Maps API / Mapbox: Map rendering and visualization
- Axios / Fetch API: API calls to backend services

## Algorithm Used

### Dijkstra’s Algorithm

The transportation network is modeled as a weighted graph:
- Nodes represent bus stops, metro stations, and walking junctions
- Edges are weighted by travel time
- Walking and mode-change connections are included as additional edges

The algorithm finds the minimum time route from source to destination across all modes.

## Input and Output

### Input:
- Source location
- Destination location

### Output:
- Optimized multi-modal route
- Transfer points and estimated times
- Map visualization with directions
- Optional alternative routes

