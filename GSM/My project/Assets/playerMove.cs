using System.Collections;
using System.Collections.Generic;
using UnityEngine;
public class playerMove : MonoBehaviour
{
    public float speed = 5;
    void Update(){
        float h = Input.GetAxis("Horizontal");
        float v = Input.GetAxis("Vertical");
        Vector3 dir = new Vector3(h,v,0);
        // transform.Translate(dir * speed * Time.deltaTime);
        transform.position += dir * speed * Time.deltaTime;
    }
}
