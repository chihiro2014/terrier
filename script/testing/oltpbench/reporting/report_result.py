#!/usr/bin/python3

import requests
from oltpbench.reporting.parse_data import parse_data
from oltpbench.constants import PERFORMANCE_STORAGE_SERVICE_API

def report(api_url, results_dir, username, password, query_mode='simple'):
    metadata, timestamp, type, parameters, metrics = parse_data(results_dir)
    parameters['query_mode'] = query_mode

    results = {
        'metadata': metadata,
        'timestamp': timestamp,
        'type': type,
        'parameters': parameters,
        'metrics': metrics
    }
    
    send_results(api_url,username,password,results)


def send_results(api_url,username,password,results):
    result = requests.post(api_url + '/oltpbench/', json=results,auth=(username,password))
    result.raise_for_status()
